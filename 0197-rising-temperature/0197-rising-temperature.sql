select w1.id as id
from weather w1 join weather w2
on w1.recordDate = date_add(w2.recordDate, interval 1 day) and w1.temperature > w2.temperature;