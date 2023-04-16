import { useState, useEffect } from "react";
import HospitalCard from "../components/hospitalCard";
import { BACKEND_URL } from '../constants';
import axios from "axios";
import { useNavigate } from "react-router-dom";
import { Notyf } from "notyf";


const Hospitals = () => {
    const notyf = new Notyf();

    const [hospitalList, setHospitalList] = useState([]);


    useEffect(() => {

        if (localStorage.getItem("hospitalList") !== null) setHospitalList(JSON.parse(localStorage.getItem("hospitalList")));

        axios.get(`${BACKEND_URL}/api/auth/hospitals`)
            .then((response) => {
                setHospitalList(response.data.hospitals)
                console.log(response)
            })
            .catch((err) => console.log(err));
    }, []);

    localStorage.setItem("hospitalList", JSON.stringify(hospitalList));



    let navigate = useNavigate();

    return (<>
        
        
        <div className="hospital-container">
        <div className="bg_move">
          <i className="fas fa-palette"></i>
          <h1 >Find a Hospital</h1>
        </div>
        

            <div className="hospital-list">
                {
                    hospitalList.map((hospital, index) => {
                        return (<HospitalCard
                            key={index}
                            name={hospital.name}
                            address={hospital.address}
                            pincode={hospital.pincode}
                            index={index} />);
                    })
                }
            </div>
        </div>
    </>

    );
}

export default Hospitals;