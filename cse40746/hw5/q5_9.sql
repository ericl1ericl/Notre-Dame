--Eric Layne hw5
--q9

with counts as (
	select city, region_code as r, count(region_code) as num
	from (
		select distinct s.state_abv, x.city, s.region_code 
		from (
			select *
			from (
				select city, count(city) as num_name
				from (
					select distinct(city), state_abv
					from allzips
				)
				group by city
				order by num_name desc
			)
			where rownum < 11
		) x, allzips a, statesinfo s
		where x.city = a.city and a.state_abv = s.state_abv
	)
	group by city, region_code
	order by city, region_code
)
select * from counts
pivot (sum(num) for r in ('1', '2', '3', '4', '5'));

exit;
