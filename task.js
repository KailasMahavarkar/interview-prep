const cookMePizza = (pizzaSize) => {
    return new Promise((resolve, reject) => {
        if (pizzaSize > 7) {
            console.log('cooking pizza');
            setTimeout(() => {
                resolve('done cooking pizza');
            }, 3000)
        } else {
            reject('error cooking pizza');
        }
    });
}

cookMePizza(4)
    .then((result) => {
        // result will become whatever we pass in resolve
        // in this case 'done cooking pizza'
        console.log(result);
    })
    .catch((error) => {
        // error will become whatever we pass in reject
        // in this case 'error cooking pizza'
        console.log(error);
    })
