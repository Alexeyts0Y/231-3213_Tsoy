    const token = "eyJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJ1c2VyIiwiaWQiOjIsImVtYWlsIjoidGVzdEB0ZXN0LnJ1Iiwicm9sZXMiOlsiR1JPVVBfNV9NRU1CRVIiXSwiaWF0IjoxNzQ5MjkwMjA1LCJleHAiOjE3NDkzMjAyMDV9.XMg1vELK7QCXrs930C0KsUGP-1Okwo3t-iqncSLALNU"
    
    function upload() {
        var files = document.querySelector("#selector").files;
        for (var i = 0; i < files.length; i++) {
            var file = files[i];
            retrieveNewURL(file, (file, url) => {
                uploadFile(file, url);
            });
        }
    }

    function retrieveNewURL(file, cb) {
        fetch(`http://localhost:8080/api/presignedUrl?name=${file.name}`, 
        {headers: {
            'Authorization': `Bearer ${token}`
        }})
        .then((response) => {
            response.text().then((url) => {
                cb(file, url);
            });
        }).catch((e) => {
            console.error(e);
        });
    }

    function uploadFile(file, url) {
        if (document.querySelector('#status').innerText === 'No uploads') {
            document.querySelector('#status').innerHTML = '';
        }
        fetch(url, {
            method: 'PUT',
            body: file
        }).then(() => {
            document.querySelector('#status').innerHTML += `<br>Uploaded ${file.name}.`;
            document.querySelector('#name').innerText = `${file.name}`;
        }).catch((e) => {
            console.error(e);
        });
    }

    function fetchImage() {
        fetch(document.querySelector("#link").innerText)
            .then((response) => {
                console.log(response.text);
            })
    }

    function getUploadLink() {
        const name = document.querySelector("#name").innerText;
        console.log(name);
        fetch(`http://localhost:8080/api/getLoadedImage?name=${name}`, {headers: {
                'Authorization': `Bearer ${token}`
            }})
            .then((response) => {
                response.text().then((url) => {
                    const link = document.querySelector("#link");
                    link.innerText = `${url}`;
                    link.innerHTML = `<a href=${url}>Link</a>`;
                    console.log(url);
                }).catch((e) => {
                console.error(e);
                })
            });
    }