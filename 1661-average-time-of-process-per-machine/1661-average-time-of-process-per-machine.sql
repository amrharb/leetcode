select machine_id as machine_id, 
        round(sum((case when activity_type = 'end' then timestamp else -timestamp end)) / count(*) * 2,3) as processing_time
from activity
group by machine_id;