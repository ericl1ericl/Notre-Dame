/* Eric Layne
	HW3 - 1 */
SELECT SL.SALE_ID, SL.SDATE, C.CUST_NAME, 
	SP.SALPERS_NAME, P.PROD_DESC, SL.QTY
FROM Sale SL, Product P, Customer C, Salesperson SP
WHERE SL.CUST_ID = C.CUST_ID AND
	SL.SALPERS_ID = SP. SALPERS_ID AND
	SL.PROD_ID = P.PROD_ID
ORDER BY SL.SALE_ID
