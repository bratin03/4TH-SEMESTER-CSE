import { useState } from "react";
import { useNavigate } from "react-router-dom";
import logout from "../utils/logout";

const Navbar = (props) => {
  const [isMobNavbarOpen, setIsMobNavbarOpen] = useState(false);

  let navigate = useNavigate();

  return (
    <div className="navbar" isopen={String(isMobNavbarOpen)}>
      <div
        className="hamburger"
        onClick={() => setIsMobNavbarOpen(!isMobNavbarOpen)}
      >
        {/* {isMobNavbarOpen ? <UilTimes /> : <UilBars />} */}
      </div>
      <div className="navbar-links">
          {
            props.data.map((option, index) => {
                return(
                <div className="link" key={index} isselected={String(props.currentSelection === index)} onClick={() => {props.changeSelection(index)}}>{option.text}</div>)
              })
          }
        <div className="link" onClick={logout}>Log Out</div>
      </div>
    </div>
  );
};

export default Navbar;
