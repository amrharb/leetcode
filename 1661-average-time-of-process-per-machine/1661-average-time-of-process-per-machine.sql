with cte as
(
    select machine_id, max(timestamp) - min(timestamp) as diff
    from activity
    group by machine_id, process_id
)
select machine_id, round(avg(diff), 3) as processing_time
from cte
group by machine_id;