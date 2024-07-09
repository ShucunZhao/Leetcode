    # Write your MySQL query statement below
    SELECT * FROM Cinema c where c.id %2!=0 
    AND c.description != "boring" ORDER BY 
    c.rating DESC