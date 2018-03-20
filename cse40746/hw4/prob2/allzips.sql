-- elayne hw4

drop table allzips;

create table allzips (
	zip varchar2(5),
        state_abv varchar2(2),
        city varchar2(26),
	primary key (zip, state_abv),
	foreign key (state_abv) references statesinfo(state_abv)
);

exit;
