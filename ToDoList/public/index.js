const form = document.getElementById('registerForm');
form.addEventListener('submit', async (e) => {
    e.preventDefault();
    const data = {
        lastName: e.target.firstName.value,
        firstName: e.target.firstName.value,
        username: e.target.username.value,
        email: e.target.email.value,
        password: e.target.password.value
    };
    const response = await fetch('/register', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(data),
    });
    const result = await response.json();
    alert(result.message);
});