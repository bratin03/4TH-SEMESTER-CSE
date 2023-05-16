import axios from "axios";
import { BACKEND_URL, FRONTEND_URL } from "../constants";

const CustomAxios = axios.create({
    baseURL: `${BACKEND_URL}` + '/api/auth/',
    headers: {
      "Content-Type": "application/json",
    }
  });

CustomAxios.interceptors.request.use(
    (config) => {
      const token = JSON.parse(localStorage.getItem("access_token"));
      if (token) {
        config.headers["Authorization"] = "Bearer " + token;
      }
      return config;
    },
    (error) => {
      return Promise.reject(error);
    }
  );
  
CustomAxios.interceptors.response.use(
    (res) => {
      return res;
    },
    async (err) => {
      const originalConfig = err.config;
      if (err.response) {
        // Access Token was expired
        if (err.response.status === 401 && !originalConfig._retry) {
          originalConfig._retry = true;
          try {
            const rs = await refreshToken();
            const { access } = rs.data;
            localStorage.setItem("access_token", JSON.stringify(access));
            CustomAxios.defaults.headers.common["Authorization"] = "Bearer " + JSON.parse(localStorage.getItem("access_token"));
            return CustomAxios(originalConfig);
          } catch (_error) {
            if (_error.response && _error.response.data) {
              return Promise.reject(_error.response.data);
            }
            return Promise.reject(_error);
          }
        }
        if (err.response.status === 403 && err.response.data) {
          return Promise.reject(err.response.data);
        }
      }
      return Promise.reject(err);
    }
  );

function refreshToken() {
    // const navigate = useNavigate()
    let refresh = JSON.parse(localStorage.getItem("refresh_token"))
    if(!refresh) refresh = 'null'
    return CustomAxios.post("token/refresh/", {
        refresh: JSON.parse(localStorage.getItem("refresh_token")),
    }).catch((err) => {
        window.location.href = `${FRONTEND_URL}/omcs/login`;
        console.log(err)
    });
  }
  
export default CustomAxios