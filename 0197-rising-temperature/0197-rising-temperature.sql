with cte as
(
    select w1.id as id, w1.temperature temp, w2.temperature as prev_temp
    from weather w1 left join weather w2
    on w1.recordDate = date_add(w2.recordDate, interval 1 day)
)

select id
from cte
where temp > prev_temp;