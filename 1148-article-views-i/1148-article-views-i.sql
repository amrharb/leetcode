with selfViews as(
    select author_id
    from views
    where author_id = viewer_id
)

select distinct author_id as id
from selfViews
order by id;