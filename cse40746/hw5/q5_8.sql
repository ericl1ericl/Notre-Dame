--Eric Layne hw5
--q8

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
select city,
	sum(case when r='1' then num else 0 end) as "Northeast",
	sum(case when r='2' then num else 0 end) as "Midwest",
	sum(case when r='3' then num else 0 end) as "Southeast",
	sum(case when r='4' then num else 0 end) as "Southwest",
	sum(case when r='5' then num else 0 end) as "West"
from counts
group by city;

exit;
