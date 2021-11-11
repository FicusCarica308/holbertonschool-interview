#!/usr/bin/node

const request = require('request');
const argv= process.argv.slice(2);

star_wars_movie_id = argv[0]

request(`https://swapi-api.hbtn.io/api/films/${star_wars_movie_id}`, function (error, response, body) {
    const characters = JSON.parse(body)['characters'];
    for (let character of characters) {
            console.log(character)
            request(character, function (error, response, body) {
                let name = JSON.parse(body)['name']
                console.log(name)
            });
    }
});
