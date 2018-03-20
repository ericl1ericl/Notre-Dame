-- elayne hw4

drop table manufacturer;

create table manufacturer (
	manufactr_id number(3),
        manufactr_name varchar2(30),
        city varchar2(30),
        country varchar2(30),
	primary key (manufactr_id)
);

exit;
