-- gp3 project

drop table tracks cascade constraints;

create table tracks (
	song_id varchar(30),
	song_name varchar(50),
	artist_id varchar(30),
	primary key (song_id)
);

exit;
