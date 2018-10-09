-- gp3 project

drop table user_artists cascade constraints;

create table user_artists (
	user_id number(11),
	artist_id varchar(30),
	popularity number(3),
	primary key (user_id, artist_id),
	foreign key (user_id) references users(user_id),
	foreign key (artist_id) references artists(artist_id)
);

exit;
