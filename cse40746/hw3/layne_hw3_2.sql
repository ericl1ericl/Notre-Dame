/* Eric Layne
	HW3 - 2 */
SELECT  sale_profit.SALPERS_NAME,
	sum(sale_profit.SL_PROFIT) AS "TOTAL_PROFIT"
FROM    (SELECT SL.SALE_ID, SL.SALPERS_ID, SP.SALPERS_NAME,
            SL.QTY*(P.PRICE-P.COST) AS "SL_PROFIT"
        FROM Sale SL, Product P, Salesperson SP
        WHERE SL.SALPERS_ID = SP.SALPERS_ID AND
            SL.PROD_ID = P.PROD_ID) sale_profit
GROUP BY sale_profit.SALPERS_NAME
