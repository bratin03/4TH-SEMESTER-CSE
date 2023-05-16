import { useNavigate } from "react-router-dom"

const NotFound = (props) => {

    const navigate = useNavigate();

    return(
        <div className="not-found">
            <div className="not-found-header">{props.header}</div>
            <div className="not-found-content">{props.content}</div>
            <div className="main-title-btn link" onClick={() => navigate("/omcs")}>
                Continue to omcs
            </div>
        </div>
    )
}

export default NotFound;