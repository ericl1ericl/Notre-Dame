-- gp3 project

drop table user_tracks cascade constraints;

create table user_tracks (
	user_id number(11),
	song_id varchar(30),
	popularity number(3),
	primary key (user_id, song_id),
	foreign key (user_id) references users(user_id),
	foreign key (song_id) references tracks(song_id)
);

exit;
