-- gp3 project

drop table playlist_users cascade constraints;

create table playlist_users (
	user_id number(11),
	playlist_id number(11),
	primary key (user_id, playlist_id),
	foreign key (user_id) references users(user_id)
);

exit;
