-- elayne hw4

drop table statesinfo;

create table statesinfo (
	state_abv varchar2(2),
        region_code int,
	state_name varchar(15),
	primary key (state_abv),
	foreign key (region_code) references regions(region_code)
);

exit;
