-- gp3 project

drop table users cascade constraints;

create table users (
	user_id number(11),
	spotify_id varchar(40) not null,
	spotify_name varchar(30) not null unique,
	primary key (user_id)
);

exit;
