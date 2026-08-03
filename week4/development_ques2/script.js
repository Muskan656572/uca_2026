const fields = [
    "First Name",
    "Last Name",
    "Email"
];

function generateForm(){
    return `
        <form>
            ${fields.map(field => `
                   <label> ${field} </label>
                   <input type = "text"> 
                `).join("")}
        </form>
    `;
}
document.getElementById("user-form").innerHTML = generateForm();