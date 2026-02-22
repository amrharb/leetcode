select id
from weather w1
where temperature > (
    select temperature
    from weather w2
    where date_sub(w1.recordDate, interval 1 day) = w2.recordDate
);