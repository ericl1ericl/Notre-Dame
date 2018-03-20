load data infile 'manufacturer.csv'
insert into table manufacturer
fields terminated by "," optionally enclosed by '"'
(manufactr_id,manufactr_name,city,country)
