-- elayne hw4

drop table customer;

create table customer (
	cust_id number(3),
        cust_name varchar2(30),
        city varchar2(25),
        country varchar2(15),
        beg_bal float,
        cur_bal float,
	primary key (cust_id)
);

exit;
