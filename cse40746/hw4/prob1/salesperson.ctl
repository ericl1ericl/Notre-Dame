load data infile 'salesperson.csv'
insert into table salesperson
fields terminated by "," optionally enclosed by '"'
(salpers_id,salpers_name,manager_id,office,comm)
