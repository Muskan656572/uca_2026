const users = [
    {name : "Alice", age: 53},
    {name : "Tim" , age: 74}
]

function generateTable(){
    return `
        <table border="1">
            ${users.map(user => `
                    <tr>
                        <td>${user.name}</td>
                        <td>${user.age}</td>
                    </tr>
                `).join("")}
        </table>
    `;
}
document.getElementById("users-data").innerHTML = generateTable();
console.log(generateTable());