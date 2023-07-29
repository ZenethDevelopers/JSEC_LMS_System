from django.shortcuts import render
from subprocess import Popen, PIPE

def compiler_view(request):
    if request.method == 'POST':
        code = request.POST.get('code'
        language = request.POST.get('language', '')
        input_value = request.POST.get('input_value', '')
        result = compile_and_execute(code, language, input_value)

        return render(request, 'compiler/compiler.html', {'code': code, 'result': result,'language':language})
    else:
        return render(request, 'compiler/compiler.html')

def compile_and_execute(code, language, input_value):
    if language == 'python':
        process = Popen(['python3', '-c', code], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    elif language == 'java':
        with open('HelloWorld.java', 'w') as c_file:
            c_file.write(code)
        process = Popen(['javac', 'HelloWorld.java'], stdin=PIPE, stdout=PIPE, stderr=PIPE)
        process.communicate()
        process = Popen(['java', 'Node'], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    elif language == 'c':
        with open('myprogram.c', 'w') as c_file:
            c_file.write(code)
        process = Popen(['gcc', 'myprogram.c', '-o', 'myprogram'], stdout=PIPE, stderr=PIPE)
        stdout, stderr = process.communicate()  # Capture the output of gcc
        if stderr:
            result = stderr.decode('utf-8')
        else:
            result = stdout.decode('utf-8')
        print("result : ", result)
        
        if process.returncode == 0:
            # Compilation successful, now run the compiled program
            process = Popen(['./myprogram'], stdin=PIPE, stdout=PIPE, stderr=PIPE)
            stdout, stderr = process.communicate(input=input_value.encode('utf-8'))
            if stderr:
                result = stderr.decode('utf-8')
            else:
                result = stdout.decode('utf-8')
            print("result : ", result)
            return result
        else:
            # Compilation failed, return the error message from gcc
            return result
    elif language in ['html', 'tailwind', 'bootstrap']:
        return f"<frame>{code}</frame>"
    elif language == 'js':
        try:
            compiled_output = eval(code)
            return compiled_output
        except Exception as e:
            return f"Error: {str(e)}"
    else:
        return 'Unsupported language'

    stdout, stderr = process.communicate(input=input_value.encode('utf-8'))
    print(stdout,stderr)
    if stderr:
        result = stderr.decode('utf-8')
    else:
        result = stdout.decode('utf-8')
    print("result : ",result)
    return result