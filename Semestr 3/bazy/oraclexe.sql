-- Sprawdź w jakim jesteś kontenerze
SELECT SYS_CONTEXT('USERENV', 'CON_NAME') FROM DUAL;

-- Sprawdź dostępne PDB
SELECT name, open_mode FROM v$pdbs;