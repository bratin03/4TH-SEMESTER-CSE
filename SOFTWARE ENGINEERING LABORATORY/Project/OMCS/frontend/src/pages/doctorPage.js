import { useNavigate } from "react-router-dom";
import { useState, useEffect } from "react";
import Navigation from "../components/navbar";
import CustomAxios from "../utils/customAxios";
import AppointmentCard from "../components/appointmentCard";

const Profile = (props) => {
  const [appointmentList, setAppointmentList] = useState([]);
  
  useEffect(() => {
    CustomAxios.get('appointments', {})
    .then((response) => {
      console.log("appointment fetch =", response);
      setAppointmentList(response.data.appointments)
      localStorage.setItem('appointmentList', JSON.stringify(response.data.appointments))

    })
    .catch((err) => {
      console.log(err)
    }) 
  }, []);

  return (
  <div className="profile">
    <div className="patient-card">
      <div className="profile-title title">{props.title}</div>
      <div className="patient-info">
        Doctor Info:
      </div>
      <div className="patient-card-name">
          Name: {props.profile.first_name} {props.profile.last_name}<br></br>
        </div>
        <div className="patient-card-name">
          Email: {props.profile.email}<br></br>
        </div>
        <div className="patient-card-name">
          Address: {props.profile.address}<br></br>
        </div>
        <div className="patient-card-name">
          PIN: {props.profile.pincode} <br></br>
        </div>
        <div className="patient-card-name">
        Contact: {props.profile.contact}<br></br>
        </div>
      </div>
    </div>

  )
}

const PendingAppointments = (props) => {
  const appointmentPassed = props.appointments.filter((appointment, index) => {
    return appointment.status == 2
  })
  return(
    <div className="appointment-list">
      {
      appointmentPassed.map((appointment, index) => {
      return(
        <AppointmentCard 
          key={index}
          id={appointment.id}
          doctor={appointment.doctor_id}
          patient={appointment.patient_id}
          date={appointment.date}
          description={appointment.description}
          byPatient={false}
          pendingByDoctor={true}
          pendingassignment={true}
        />
      )
    })
  }
    </div>
  )
}

const AppointmentHistory = (props) => {
  return(
    <div className="appointment-list">
      {
        props.appointments.map((appointment, index) => {
          return(
            <AppointmentCard 
            key={index}
            id={appointment.id}
            doctor={appointment.doctor_id}
            patient={appointment.patient_id}
            date={appointment.date}
            status={appointment.status}
            description={appointment.description}
            />
          )
        })
      }
    </div>
  )
}

const DoctorPage = () => {

  const [appointmentList, setAppointmentList] = useState([]);
  const [userDetail, setUserDetail] = useState({});
  const [patientList, setPatientList] = useState([]);

  let navigate = useNavigate();

  const navData = [
    {
      'text': 'Profile',
      'icon': null
    },
    {
      'text': 'Pending Appointments',
      'icon': null
    },
    {
      'text': 'Appointment history',
      'icon': null
    }
  ]

  const [currentSelection, setCurrentSelection] = useState(0);
  const [userList, setUserList] = useState([]);
  const [filterList, setFilterList] = useState([]);

  var title, BodyContent;

  if (currentSelection === 0) {
      title = "PROFILE";
      BodyContent = Profile;
  }
  else if (currentSelection === 1) {
      title = "PENDING APPOINTMENTS";
      BodyContent = PendingAppointments;
  }
  else {
      title = "APPOINTMENT HISTORY";
      BodyContent = AppointmentHistory;
  }

  useEffect(() => {
    setUserDetail(JSON.parse(localStorage.getItem("userDetail")))
    CustomAxios.get('appointments', {})
    .then((response) => {
      console.log("appointment fetch =", response);
      setAppointmentList(response.data.appointments)
      CustomAxios.get('patients', {})
      .then((response) => {
        console.log("patients =", response);
        setPatientList(response.data.patients)
        localStorage.setItem("patientList", JSON.stringify(response.data.patients))
      })
      .catch((err) => {
        console.log(err)
    });

    })
    .catch((err) => {
      console.log(err)
    });
  }, []);

  return(
    <div className="admin-page">
      <Navigation 
        data={navData} 
        currentSelection={currentSelection}
        changeSelection={setCurrentSelection} />
      
    <BodyContent 
    title={title} 
    profile={userDetail}
    appointments={appointmentList}
    />
  </div>
  )
}

export default DoctorPage;