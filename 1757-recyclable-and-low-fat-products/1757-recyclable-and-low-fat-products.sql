SELECT
    product_id
FROM
    Products
Where
    low_fats = 'Y' and recyclable = 'Y'
ORDER BY
    product_id