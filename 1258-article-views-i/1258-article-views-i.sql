# Write your MySQL query statement below
-- use distinct 
-- SELECT  distinct viewer_id AS id FROM views WHERE author_id=viewer_id ORDER BY id ASC


SELECT viewer_id AS id FROM views WHERE author_id=viewer_id GROUP BY id ORDER BY id ASC
