import { BrowserRouter, Routes, Route } from "react-router-dom";
import LandingPage from "./views/landingPage";
import MainPage from "./views/mainPage";
import Hospitals from "./views/hospitals";
import DoctorRegisterCard from "./components/doctorRegisterCard";
import PatientRegisterCard from "./components/patientRegisterCard";
import LoginCard from "./components/loginCard";
import ProfilePage from "./views/profilePage";
import NotFound from "./pages/notFound";

import 'notyf/notyf.min.css';

function App() {
  return (
    <div className="App">
      <BrowserRouter>
        <Routes>
          <Route path="/" element={<MainPage />} />
          <Route path="/omcs" element={<MainPage />} />
          <Route path="/omcs/hospitals" element={<Hospitals />} />
          <Route path="/omcs/register/doctor" element={<DoctorRegisterCard />} />
          <Route path="/omcs/register/patient" element={<PatientRegisterCard />} />
          <Route path="/omcs/login" element={<LoginCard />} />
          <Route path="/omcs/me" element={<ProfilePage />} />
          <Route path="/omcs/404" element={<NotFound />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
