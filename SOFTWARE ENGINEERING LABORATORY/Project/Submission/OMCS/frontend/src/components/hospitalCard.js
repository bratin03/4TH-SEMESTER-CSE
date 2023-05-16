const colors = ['#3ecd5e', '#e44002', '#952aff', '#cd3e94', '#4c49ea', '#ff6b6b', '#00adb5'];


const HospitalCard = (props) => {
    const color = colors[props.index % colors.length];
    return (
        <div className="ag-format-container">
            <div className="ag-courses_box">
                <div className="ag-courses_item">
                    <div className="ag-courses-item_link">

                        <div className="ag-courses-item_bg" style={{ backgroundColor: color }}></div>

                        <div className="ag-courses-item_title">
                            {props.name}&nbsp;
                        </div>

                        <div className="ag-courses-item_date-box">
                            Address: &nbsp;&nbsp;&nbsp;{props.address}<br></br>
                            <span className="ag-courses-item_date">
                                Pin Code: &nbsp;&nbsp;&nbsp;{props.pincode}
                            </span>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    )
}





// const HospitalCard = (props) => {
//     return (
//         // <div classNameName="hospital-card">
//         //     <div classNameName="hospital-title">{props.name}</div>
//         //     <div classNameName="hospital-address">{props.address}</div>
//         //     <div classNameName="hospital-pincode">{props.pincode}</div>
//         // </div>

//         <div className="ag-format-container">
//             <div className="ag-courses_box">
//                 <div className="ag-courses_item">
//                     <div className="ag-courses-item_link">

//                         <div className="ag-courses-item_bg"></div>

//                         <div className="ag-courses-item_title">
//                             {props.name}&nbsp;
//                         </div>

//                         <div className="ag-courses-item_date-box">
//                             Address: &nbsp;&nbsp;&nbsp;{props.address}<br></br>
//                             <span className="ag-courses-item_date">
//                                 Pin Code: &nbsp;&nbsp;&nbsp;{props.pincode}
//                             </span>
//                         </div>
//                     </div>
//                 </div>
//             </div>
//         </div>
//     )
// }

export default HospitalCard;



