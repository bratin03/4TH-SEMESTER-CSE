import { FRONTEND_URL } from "../constants";

const logout = () => {
    localStorage.removeItem("access_token")
    localStorage.removeItem("refresh_token")
    window.location.href = `${FRONTEND_URL}/omcs/`;
}

export default logout