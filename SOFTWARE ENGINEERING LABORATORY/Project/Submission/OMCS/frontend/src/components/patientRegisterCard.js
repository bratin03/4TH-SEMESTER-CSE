import React, { useState, useEffect } from 'react';
import { BACKEND_URL } from '../constants';
import axios from 'axios';
import { useNavigate } from 'react-router-dom';
import { Notyf } from 'notyf';

const PatientRegisterCard = () => {

  const notyf = new Notyf();

  const navigate = useNavigate()

  const [email, setEmail] = useState("")
  const [password, setPassword] = useState("")
  const [name, setName] = useState("")
  const [lastname, setLastname] = useState("")
  const [address, setAddress] = useState("")
  const [contact, setContact] = useState("")
  const [pin, setPin] = useState("")


  const onLoginFormSubmit = (event) => {
    event.preventDefault();
    // console.log(email, password, role)
    axios.post(`${BACKEND_URL}/api/auth/register`, {
            email: email,
            password: password,
            role: 3,
            first_name: name,
            last_name: lastname,
            address: address,
            contact: contact,
            pincode: pin
        }).then(
            result => {
              console.log(result.data)
              console.log("USER created successfully")
              notyf.success("User created successfully")
              navigate("/omcs/login")
            }
    ).catch (error => {
        console.log(error);
        notyf.error("Email is already in use")
    })
  }
  function validateForm() {
    return email.length > 0 && password.length > 0;
  }
  return (
    <div className="Login">
      <div className="form-title">Register</div>
      <form onSubmit={onLoginFormSubmit} className="login-form">
        <div className="form-group">
          {/* <label className="form-label">Email</label> */}
          <input
            placeholder='Email'
            required
            autoFocus
            type="email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
          />
        </div>
        <div className="form-group">
          {/* <label className="form-label">Password</label> */}
          <input
            placeholder='Password'
            required
            type="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
          />
        </div>

        <div className="form-group">
          {/* <label className="form-label">Name</label> */}
          <input
            placeholder='First Name'
            required
            type="name"
            value={name}
            onChange={(e) => setName(e.target.value)}
          />
        </div>

        <div className="form-group">
          {/* <label className="form-label">Last Name</label> */}
          <input
            placeholder='Last Name'
            required
            type="lastname"
            value={lastname}
            onChange={(e) => setLastname(e.target.value)}
          />
        </div>

        <div className="form-group">
          {/* <label className="form-label">Address</label> */}
          <input
            placeholder='Address'
            required
            type="address"
            value={address}
            onChange={(e) => setAddress(e.target.value)}
          />
        </div>

        <div className="form-group" >
          {/* <label className="form-label">Contact</label> */}
          <input
            placeholder='Contact'
            required
            type="contact"
            value={contact}
            onChange={(e) => setContact(e.target.value)}
          />
        </div>
        
        <div className="form-group">
        {/* <label className="form-label">Pin code</label> */}
        <input
            placeholder='Pin Code'
            required
            type="pincode"
            value={pin}
            onChange={(e) => setPin(e.target.value)}
          />
        </div>

        <button type="submit" className="form-button" disabled={!validateForm()}>
          Register
        </button>
      </form>
    </div>
  );
}

export default PatientRegisterCard;
