const MAX_CASES = 1001;

let total,
    npermut,
    minCase,
    maxCase,
    n = 4,
    prob,
    cases;

let element;

function isortSteps(aux) {
    let steps = 0,
        i = 0,
        j, k,
        v = new Array(aux.length);
    for (let num of aux) {
        v[i++] = num;
    }
    for (i = 1; i < v.length; ++i) {
        x = v[i];
        j = i - 1;
        while (j > -1 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
            steps++;
        }
        if (j != -1) {
            steps++;
        }
        v[j + 1] = x;
    }
    return steps;
}

function swap(v, i, j) {
    let x = v[i];
    v[i] = v[j];
    v[j] = x;
}

function perm(v, i, n) {
    let j = k = 0;
    if (i == n) {
        npermut++;
        k = isortSteps(v);
        total += k;
        cases[k]++;
    } else {
        for (j = i; j < n; j++) {
            swap(v, i, j);
            perm(v, i + 1, n);
            swap(v, i, j);
        }
    }
}

function init() {
    let view = document.getElementById('view-frame');
    let graphElem = document.createElement('div');
    let distribution = document.createElement('div');
    let graphic = document.createElement('div');
    let info = document.createElement('div');

    view.className += " row view-frame justify-content-center";
    graphElem.className = "col-md-9 col-12 no-gutters";
    graphElem.id = "graphElem";
    graphElem.align = "center";
    distribution.className = "col-md-3 col-12";
    distribution.id = "distribution";
    graphic.setAttribute('id', 'graphic');
    info.setAttribute('id', 'info');

    info.innerHTML = "n = <label id='n_label'></label><br>" +
        "Number of Permutations = <label id='n_perm_label'></label><br>" +
        "Average Numbre of Steps = <label id= 'a_n_steps_label'></label> <br>";
    distribution.innerHTML = " <label> Distribution </label>" +
        "<ul id = 'dist-list' type = \"none\"> </ul>";
    graphElem.innerHTML = "<label>  Enter n: <input id = 'input' type = \"number\"> </input> </label>";
    graphElem.appendChild(graphic);
    graphElem.appendChild(info);


    view.appendChild(graphElem);
    view.appendChild(distribution);
    let input = document.getElementById('input');
    input.placeholder = n;
    input.defaultValue = n;
    console.log(input.defaultValue);
    input.oninput = function() {
        restart()
    };
}

function restart() {
    n = document.getElementById('input').value;
    start();
}

function start() {
    let v = [],
        x = [],
        y;
    let k;
    total = 0;
    npermut = 0;
    minCase = MAX_CASES - 1;
    maxCase = 0;
    prob = [];
    cases = [];
    for (k = 0; k < MAX_CASES; k++) {
        prob[k] = 0.0;
        cases[k] = 0;
    }

    for (k = 0; k < n; k++) {
        v[k] = k + 1;
    }
    perm(v, 0, n);
    for (k = 0; k < MAX_CASES; k++) {
        prob[k] = cases[k] / npermut;
        if (cases[k] > 0) {
            x.push(k);
        }
    }

    y = prob.filter(item => item > 0);
    let graph = document.getElementById('graphic');

    Plotly.newPlot(graph, [{
        x: x,
        y: y,
        type: 'bar',
    }], {
        title: 'Comparations Distribution',
        font: {size: 18},
    },{
        responsive: true
    });

    let n_label = document.getElementById('n_label');
    let n_perm_label = document.getElementById('n_perm_label');
    let a_n_steps_label = document.getElementById('a_n_steps_label');

    n_label.innerHTML = n;
    n_perm_label.innerHTML = npermut;
    a_n_steps_label.innerHTML = total / npermut;

    let dist_list = document.getElementById('dist-list');
    let li;
    dist_list.innerHTML = "";
    for (step of x) {
        li = document.createElement('li');
        li.innerHTML = step + " => " + prob[step].toFixed(6);
        dist_list.appendChild(li);
    }


}

init();
start();
