--------------------------------------------------------
--  DDL for Table PAYMENTMETHOD
--------------------------------------------------------

  CREATE TABLE "PAYMENTMETHOD" 
   (	"PAYMENTMETHODKEY" NUMBER(2,0), 
	"PAYMENTMETHODNAME" VARCHAR2(20)
   );
--------------------------------------------------------
--  DDL for Index PAYMENTMETHOD_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "PAYMENTMETHOD_PK" ON "PAYMENTMETHOD" ("PAYMENTMETHODKEY");

--------------------------------------------------------
--  DDL for Index PAYMENT_NAME_UQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "PAYMENT_NAME_UQ" ON "PAYMENTMETHOD" ("PAYMENTMETHODNAME");

--------------------------------------------------------
--  Constraints for Table PAYMENTMETHOD
--------------------------------------------------------

  ALTER TABLE "PAYMENTMETHOD" ADD CONSTRAINT "PAYMENTMETHOD_PK" PRIMARY KEY ("PAYMENTMETHODKEY") ENABLE;

  ALTER TABLE "PAYMENTMETHOD" ADD CONSTRAINT "PAYMENT_NAME_UQ" UNIQUE ("PAYMENTMETHODNAME") ENABLE;
 
  ALTER TABLE "PAYMENTMETHOD" MODIFY ("PAYMENTMETHODKEY" NOT NULL ENABLE);
 
  ALTER TABLE "PAYMENTMETHOD" MODIFY ("PAYMENTMETHODNAME" NOT NULL ENABLE);
