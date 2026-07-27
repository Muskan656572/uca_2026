self.onmessage = async function () {

    try {

        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const result = await response.json();

        // Creating the structure expected by the assignment
        const users = result.users.map(user => ({
            name: `${user.firstName} ${user.lastName}`,
            active: Math.random() > 0.5
        }));

        self.postMessage({
            success: true,
            data: users
        });

    } catch (error) {

        self.postMessage({
            success: false,
            error: error.message
        });

    }

};