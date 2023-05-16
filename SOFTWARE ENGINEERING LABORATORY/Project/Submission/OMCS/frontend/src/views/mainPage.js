import { useState, useEffect } from "react";
import { useNavigate } from "react-router-dom";
import { UilStethoscopeAlt } from '@iconscout/react-unicons'

const MainPage = () => {

  let navigate = useNavigate();
  const [currentText, setCurrentText] = useState(0);
  const texts = ["Welcome to MedBud", "Find the right medical care for you", "Join the MedBud community today"];

  useEffect(() => {
    const interval = setInterval(() => {
      setCurrentText((currentText + 1) % texts.length);
    }, 3000); // change text every 3 seconds
    return () => clearInterval(interval);
  }, [currentText, texts.length]);

  return (
    <div className="main-page">
      <div className="main-header">
        <div className="main-header-sf">
          <UilStethoscopeAlt className="main-header-icon" />OMCS
        </div>
        <div className="main-btns">
          <div className="main-title-btn link" onClick={() => navigate("/omcs/hospitals")}>
            Hospitals
          </div>
          <div className="main-title-btn link" onClick={() => navigate("/omcs/register/doctor")}>
            Doctor Register
          </div>
          <div className="main-title-btn link" onClick={() => navigate("/omcs/register/patient")}>
            Patient Register
          </div>
          <div className="main-title-btn link" onClick={() => navigate("/omcs/login")}>
            Login
          </div>
        </div>

      </div>
      <div className="main-title">

        <div className="bg_move">
          <i className="fas fa-palette"></i>
          <h1>{texts[currentText]}</h1>
        </div>
        
      </div>
    </div>
  );
}

export default MainPage;
