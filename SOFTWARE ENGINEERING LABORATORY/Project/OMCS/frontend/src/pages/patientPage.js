import { useState, useEffect } from "react";
import Navigation from "../components/navbar";
import CustomAxios from "../utils/customAxios";
import DoctorCard from "../components/doctorCard";
import AppointmentCard from "../components/appointmentCard";
// import { UilTimes } from '@iconscout/react-unicons';
import { UilSearch } from '@iconscout/react-unicons'

import DatePicker from "react-datepicker";
import "react-datepicker/dist/react-datepicker.css";

const Profile = (props) => {
  return (
    <div className="profile">
      <div className="patient-card">
        <div className="profile-title title">{props.title}</div>
        <div className="patient-info">
          Patient Info:
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

const Errors = () => {
  return (
    <div className="appointment">
      Enter PIN Code
    </div>
  )
}

const BookAppointmentContent = (props) => {
  const [startDate, setStartDate] = useState(new Date());
  return (
    <div className="appointment-content">
      <div className="appointment-date">
        <label className="type-label">Select Date: </label>
        <DatePicker wrapperClassName="datePicker" className="picker" selected={startDate} onChange={(date) => setStartDate(date)} />
      </div>
      {
        props.availDoctorList.map((doctor, index) => {
          return (
            <DoctorCard
              key={index}
              id={doctor.id}
              name={doctor.first_name}
              lastname={doctor.last_name}
              hospital={doctor.hospital}
              speciality={doctor.speciality}
              address={doctor.address}
              pincode={doctor.pincode}
              contact={doctor.contact}
              email={doctor.email}
              date={startDate}
              byPatient={true}
            />
          )
        })
      }
    </div>
  )
}

const BookAppointment = (props) => {

  const [pincode, setPincode] = useState("");
  const [doctorList, setDoctorList] = useState([])
  const [availDoctorList, setAvailDoctorList] = useState([])
  const [show, setShow] = useState(false);

  function checkPincode() {
    return (/^\d+$/.test(pincode) && pincode.length == 6);
  }

  function pincodeSearch(event) {
    event.preventDefault();
    setShow(true)
    let availableDoctors;
    if (pincode == "") {
      availableDoctors = doctorList;
    } else {
      availableDoctors = doctorList.filter((doctor, index) => {
        return doctor.pincode == pincode
      })
    }

    setAvailDoctorList(availableDoctors)
    console.log(availDoctorList)
  }

  useEffect(() => {
    CustomAxios.get('doctors')
      .then((response) => {
        console.log(response)
        setDoctorList(response.data.doctors)
        localStorage.setItem("doctors", JSON.stringify(response.data.doctors))
      })
      .catch((err) => console.log(err))
  }, []);

  let BodyContent;
  console.log(show)
  if (show) BodyContent = BookAppointmentContent
  else BodyContent = Errors

  return (
    <div className="appointment-container">
      <div className="appointment-pincode">
        {/* <label className="type-label">Input pin code: </label>   */}
        <input className="pincode-input pincode-child" type="text" placeholder="PIN CODE" onChange={(e) => {
          setPincode(e.target.value)
          if (!(/^\d+$/.test(pincode) && pincode.length === 6)) { setShow(false) }
        }} value={pincode} />
        <button className="pincode-button pincode-child" disabled={!checkPincode} onClick={pincodeSearch}>
          {/* <FontAwesomeIcon  className="pincode-icon" icon={faArrowAltCircleRight} /> */}
          <UilSearch color="white" />
        </button>
      </div>
      <BodyContent availDoctorList={availDoctorList} />
    </div>
  )
}

const AppointmentHistory = (props) => {
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
    <div className="appointment-list">
      {
        appointmentList.map((appointment, index) => {
          return (
            <AppointmentCard
              key={index}
              id={appointment.id}
              doctor={appointment.doctor_id}
              patient={appointment.patient_id}
              date={appointment.date}
              description={appointment.description}
              byPatient={true}
              status={appointment.status}
            // pending={true}
            />
          )
        })
      }
    </div>
  )
}


const PatientPage = () => {

  const [userDetail, setUserDetail] = useState({});
  const [currentSelection, setCurrentSelection] = useState(0);

  const navData = [
    {
      'text': 'Profile',
      'icon': null
    },
    {
      'text': 'Book an appointment',
      'icon': null
    },
    {
      'text': 'Appointment history',
      'icon': null
    }
  ]

  var title, BodyContent;

  if (currentSelection === 0) {
    title = "PROFILE";
    BodyContent = Profile;
  }
  else if (currentSelection === 1) {
    title = "BOOK APPOINTMENT";
    BodyContent = BookAppointment;
  }
  else {
    title = "APPOINTMENT HISTORY";
    BodyContent = AppointmentHistory;
  }

  useEffect(() => {
    setUserDetail(JSON.parse(localStorage.getItem("userDetail")));
    console.log("userdetail =", userDetail)
    CustomAxios.get('me')
      .then((response) => {
        setUserDetail(response.data.me)
      })
      .catch((err) => console.log(err))
  }, []);

  return (
    <div className="patient-page">
      <Navigation
        data={navData}
        currentSelection={currentSelection}
        changeSelection={setCurrentSelection} />

      <BodyContent
        title={title}
        profile={userDetail} />
    </div>
  )
}

export default PatientPage;