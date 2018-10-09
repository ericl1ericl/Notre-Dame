-- gp3 project

drop table artists cascade constraints;

create table artists (
	artist_id varchar(30),
	artist_name varchar(50),
	genre varchar(30),
	primary key (artist_id)
);

exit;
