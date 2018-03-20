--Eric Layne hw5
--q7

select r.region_name, s.state_name
from statesinfo s, regions r
where s.region_code = r.region_code
order by s.region_code;

exit;
