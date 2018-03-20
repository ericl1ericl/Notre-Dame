load data infile 'allzips.csv'
insert into table allzips
fields terminated by "," optionally enclosed by '"'
(zip,state_abv,city)
