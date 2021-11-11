#!/usr/bin/node

const request = require('request');
const argv= process.argv.slice(2);

star_wars_movie_id = argv[0]

request(`https://swapi-api.hbtn.io/api/films/${star_wars_movie_id}`, async function (error, response, body) {
    const character_urls = JSON.parse(body)['characters'];
    for (let url of character_urls) {
        await new Promise(function (resolve, reject) {
            request(url, function (error, response, body) {
                console.log(JSON.parse(body)['name'])
                resolve()
            });
        });
    }
});
