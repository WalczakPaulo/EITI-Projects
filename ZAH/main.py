from pulp import *


mon = pulp.LpVariable('mon', 0, 100, 'Integer')
tue = pulp.LpVariable('tue', 0, 100, 'Integer')
wed = pulp.LpVariable('wed', 0, 100, 'Integer')
thu = pulp.LpVariable('thu', 0, 100, 'Integer')
fri = pulp.LpVariable('fri', 0, 100, 'Integer')
sat = pulp.LpVariable('sat', 0, 100, 'Integer')
sun = pulp.LpVariable('sun', 0, 100, 'Integer')


workersProb = LpProblem('prob', LpMinimize)


workersProb += mon + tue + wed + thu + fri >= 20
workersProb += tue + wed + thu + fri + sat >= 20
workersProb += wed + thu + fri + sat + sun >= 20
workersProb += thu + fri + sat + sun + mon >= 12
workersProb += fri + sat + sun + mon + tue >= 12
workersProb += sat + sun + mon + tue + wed >= 12
workersProb += sun + mon + tue + wed + thu >= 12


workersProb += mon + tue + wed + thu + fri + sat + sun

status = workersProb.solve()
LpStatus[status]

print('Mon - ' + str(value(mon)))
print('Tue - ' + str(value(tue)))
print('Wed - ' + str(value(wed)))
print('Thu - ' + str(value(thu)))
print('Fri - ' + str(value(fri)))
print('Sat - ' + str(value(sat)))
print('Sun - ' + str(value(sun)))

