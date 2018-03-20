load data infile 'statesinfo.csv'
insert into table statesinfo
fields terminated by "," optionally enclosed by '"'
(state_abv,region_code,state_name)
