const usersDiv = document.getElementById("users");

const worker = new Worker("./worker.js");

worker.postMessage("fetch");

worker.onmessage = function (event) {

    const result = event.data;

    if (!result.success) {
        usersDiv.innerHTML = "No users found";
        return;
    }

    const users = result.data;

    if (!users || users.length === 0) {
        usersDiv.innerHTML = "No users found";
        return;
    }

    usersDiv.innerHTML = "";

    users.forEach(user => {

        const p = document.createElement("p");

        p.textContent = `${user.name} - ${user.active ? "Active" : "Inactive"}`;

        usersDiv.appendChild(p);

    });

};