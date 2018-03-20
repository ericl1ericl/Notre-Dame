/* Eric Layne
	HW3 - 3 */
SELECT S2.Manager_ID,
    count(S2.Salpers_ID) AS "Num_Managed"
FROM Salesperson S1, Salesperson S2
WHERE S1.Salpers_ID = S2.Manager_ID
GROUP BY S2.Manager_ID
ORDER BY S2.Manager_ID
