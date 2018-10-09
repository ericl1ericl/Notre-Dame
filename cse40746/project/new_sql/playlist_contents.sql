-- gp3 project

drop table playlist_contents cascade constraints;

create table playlist_contents (
	playlist_id number(11),
	song_id varchar(30),
	primary key (playlist_id, song_id),
	foreign key (song_id) references tracks(song_id)
);

exit;
