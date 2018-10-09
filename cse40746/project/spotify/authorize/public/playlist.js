var access_token = document.cookie;
var playSrc = document.getElementById('playlists-template').innerHTML,
  playTemplate = Handlebars.compile(playSrc),
  playLoc = document.getElementById('playlists');


$(document).ready(function() {
  $.ajax({
    url: '/getPlaylist',
  }).done(function(d) {
    // results as pid, spotify_name, song_name in arr
    if (d.get_playlist) {
      p_list = d.get_playlist;
    } else {
      p_list = []
    }
    let plists = new Set();
    let sanitized = {}
    let info = {}

    p_list.forEach(function(e) {
      plists.add(e[0]);
    });

    plists.forEach(function (el) {

    })

    p_list.forEach(function (el) {
        if (sanitized[el[0]]) {
          sanitized[el[0]]['songs'].push({'name': el[2], 'artist': el[3]})
        } else {
        sanitized[el[0]] = { 'songs': [{'name': el[2], 'artist': el[3]}],
          'user': el[1] }
        }
    })

    console.log(sanitized)

    playLoc.innerHTML = playTemplate(sanitized)
    })

  });
