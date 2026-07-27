const worker = new Worker("./worker.js");

// Start the worker
worker.postMessage("fetch");

// Receive data from worker
worker.onmessage = function (event) {

    const result = event.data;

    if (!result.success) {
        console.error("No users found");
        return;
    }

    const users = result.data;

    if (!users || users.length === 0) {
        console.error("No users found");
        return;
    }

    users.forEach(user => {

        console.log(
            `${user.name} - ${user.active ? "Active" : "Inactive"}`
        );

    });

};