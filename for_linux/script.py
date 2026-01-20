#!/usr/bin/env python3
"""
生成 ctags 和 cscope 索引脚本
适用于 Linux 环境，支持 C/C++/Verilog/SystemVerilog 文件
"""
import os
import subprocess

def run_command(cmd, description):
    """执行系统命令并捕获执行状态，输出日志信息"""
    print(f"[INFO] {description}")
    try:
        result = subprocess.run(
            cmd,
            shell=True,
            check=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        return True
    except subprocess.CalledProcessError as e:
        print(f"[ERROR] 命令执行失败: {description}")
        print(f"[ERROR] 错误输出: {e.stderr.strip()}")
        return False

def main():
    # 获取脚本所在的绝对目录（不受工作目录影响）
    script_dir = os.path.dirname(os.path.abspath(__file__))
    # 定义文件路径
    tags_path = os.path.join(script_dir, "tags")
    cscope_files_path = os.path.join(script_dir, "cscope.files")
    # 支持的文件后缀（可根据需求扩展）
    supported_extensions = ["'*.h'", "'*.c'", "'*.v'", "'*.sv'", "'*.svh'","'*.py'"]

    # 分隔线
    print("-" * 60)

    # 1. 清理旧索引文件
    run_command(f"rm -f {tags_path}", "清理旧 ctags 索引文件")
    run_command(f"rm -f {os.path.join(script_dir, 'cscope*')}", "清理旧 cscope 索引文件")

    # 2. 生成 ctags 索引
    if run_command(f"ctags -R {script_dir}", "生成 ctags 全局索引"):
        print(f"[SUCCESS] ctags 索引已生成至 {tags_path}")

    # 3. 生成 cscope.files 文件列表
    run_command(f"rm -f {cscope_files_path}", "清理旧 cscope 文件列表")
    #find_cmd = f"find {script_dir} \( -name " + " -o -name ".join(supported_extensions) + f"\) > {cscope_files_path}"
    # 修正后的代码
    find_cmd = f"find \"{script_dir}\" \\( -name {' -o -name '.join(supported_extensions)} \\) > \"{cscope_files_path}\""
    print(find_cmd)
    if run_command(find_cmd, "收集目标文件到 cscope.files"):
        # 4. 生成 cscope 索引
        if run_command(f"cscope -bqk -i {cscope_files_path}", "生成 cscope 索引"):
            print(f"[SUCCESS] cscope 索引已生成至 {script_dir}")

    # 分隔线
    print("-" * 60)

if __name__ == "__main__":
    main()

